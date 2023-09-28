import json
from bs4 import BeautifulSoup
import urllib.request
import csv
import datetime
import re
import sqlite3

from html_scraper import get_new_urls

import os

# Credit: Chat GPT, because original code resulted in 403 error
user_agent = 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.3'
headers = {'User-Agent': user_agent}

def get_soup_from_url(url):
    request = urllib.request.Request(url, headers=headers)
    response = urllib.request.urlopen(request)
    html_content = response.read()
    return BeautifulSoup(html_content, "html.parser")

def getVoteLinks(URL, page): 
    soup = get_soup_from_url(URL)

    table = soup.find_all(class_="table--list")[0]
    rows = table.find_all(class_="list__row")

    links = []

    for row in rows:
        cell = row.find_all('a')[0]
        link = "https://www.parliament.nz" + cell.get('href')
        links.append(link)

    next_page = soup.find_all(class_="pagination__next")

    if len(next_page) == 1:
        link = url + "&Criteria.PageNumber=" + str(page+1)
        links.extend(getVoteLinks(link, page+1))

    return links

def getVotesAndHeader(URL):
    soup = get_soup_from_url(URL)

    header = soup.find_all(class_="gamma")
    if len(header) > 0:
        header = header[0].get_text()
    else:
        header = None

    tables = soup.find_all(class_="table")
    ayes_table = tables[0]
    noes_table = tables[1]
    
    ayes_td = ayes_table.find_all('td')
    noes_td = noes_table.find_all('td')

    ayes = []
    noes = []
    for td in ayes_td:
        name = td.text
        if name.endswith("(P)"):
            name = name[:-3].rstrip()
        ayes.append(name)
    
    for td in noes_td:
        name = td.text
        if name.endswith("(P)"):
            name = name[:-3].rstrip()
        noes.append(name)

    return ayes, noes, header

def getFullName(name, full_names):
    name_split = name.split(" ")
    last_name = name_split[0]
    if len(name_split) == 2:
        first_initial = name_split[1]
    else:
        first_initial = ""
    for full_name in full_names:
        parts = full_name.split()
        if len(parts) >= 2:
            full_first_name = parts[0]
            full_last_name = parts[1]
            
            if full_last_name == last_name:
                if first_initial == "" or full_first_name.startswith(first_initial):
                    return full_name
    
    return None  # Return None if no match is found

def getListOfMpNames():
    conn = sqlite3.connect("../../qtGuiApplication/parliament.db")
    cursor = conn.cursor()
    cursor.execute("SELECT name FROM mps")
    names = cursor.fetchall()
    mps = [name[0] for name in names]
    cursor.close()
    conn.close()
    return mps

def getFullNameList(names, mps):
    full_names = []
    for name in names:
            if name != "":
                fullName = getFullName(name, mps)
                if fullName != None:
                    full_names.append(getFullName(name, mps))
    return full_names

def write_vote_to_csv(header, ayes, noes):
    with open("votes.csv", mode='a', newline='', encoding="utf-8" ) as file:
        csv_writer = csv.writer(file)
        ayes_string = ""
        for aye in ayes:
            ayes_string += aye + "!"
        noes_string = ""
        for noe in noes:
            noes_string += noe + "!"
        csv_writer.writerow([header, ayes_string, noes_string])

def init_csv_files():
    with open("votes.csv", mode='w', newline='', encoding="utf-8" ) as file:
        csv_writer = csv.writer(file)
        csv_writer.writerow(['Vote', 'Ayes', 'Noes'])

if __name__ == "__main__":
    mps = getListOfMpNames()
    '''
    URLS = ["https://www.parliament.nz/en/pb/hansard-debates/rhr/search?criteria.Keyword=%22A+personal+vote+was+called+for+on+the+question%22&criteria.ParliamentNumber=53&criteria.Timeframe=&criteria.DateFrom=2020-11-24&criteria.DateTo=&parliamentStartDate=2020-11-24&parliamentEndDate=&criteria.Portfolio=&criteria.Dt=Hansard+-+vote",
            "https://www.parliament.nz/en/pb/hansard-debates/rhr/search?criteria.Keyword=%22A+personal+vote+was+called+for+on+the+question%22&criteria.ParliamentNumber=52&criteria.Timeframe=&criteria.DateFrom=2017-11-07&criteria.DateTo=2020-11-20&parliamentStartDate=2017-11-07&parliamentEndDate=2020-11-20&criteria.Portfolio=&criteria.Dt=Hansard+-+vote",
            "https://www.parliament.nz/en/pb/hansard-debates/rhr/search?criteria.Keyword=%22A+personal+vote+was+called+for+on+the+question%22&criteria.ParliamentNumber=51&criteria.Timeframe=&criteria.DateFrom=2014-10-07&criteria.DateTo=2017-08-22&parliamentStartDate=2014-10-07&parliamentEndDate=2017-08-22&criteria.Portfolio=&criteria.Dt=Hansard+-+vote",
            "https://www.parliament.nz/en/pb/hansard-debates/rhr/search?criteria.Keyword=%22A+personal+vote+was+called+for+on+the+question%22&criteria.ParliamentNumber=50&criteria.Timeframe=&criteria.DateFrom=2011-12-13&criteria.DateTo=2014-08-14&parliamentStartDate=2011-12-13&parliamentEndDate=2014-08-14&criteria.Portfolio=&criteria.Dt=Hansard+-+vote",
            "https://www.parliament.nz/en/pb/hansard-debates/rhr/search?criteria.Keyword=%22A+personal+vote+was+called+for+on+the+question%22&criteria.ParliamentNumber=49&criteria.Timeframe=&criteria.DateFrom=2008-12-08&criteria.DateTo=2011-10-20&parliamentStartDate=2008-12-08&parliamentEndDate=2011-10-20&criteria.Portfolio=&criteria.Dt=Hansard+-+vote",
            "https://www.parliament.nz/en/pb/hansard-debates/rhr/search?criteria.Keyword=%22A+personal+vote+was+called+for+on+the+question%22&criteria.ParliamentNumber=48&criteria.Timeframe=&criteria.DateFrom=2005-11-07&criteria.DateTo=2008-10-03&parliamentStartDate=2005-11-07&parliamentEndDate=2008-10-03&criteria.Portfolio=&criteria.Dt=Hansard+-+vote",
            "https://www.parliament.nz/en/pb/hansard-debates/rhr/search?criteria.Keyword=%22A+personal+vote+was+called+for+on+the+question%22&criteria.ParliamentNumber=47&criteria.Timeframe=&criteria.DateFrom=2002-08-20&criteria.DateTo=2005-08-11&parliamentStartDate=2002-08-20&parliamentEndDate=2005-08-11&criteria.Portfolio=&criteria.Dt=Hansard+-+vote"]

    links = []
    for url in URLS:
        print(url)
        links.extend(getVoteLinks(url, 1))

    with open("valid_links.txt", 'w') as file:
        for link in links:
            file.write(link + '\n') 
    '''
    links = []
    with open("valid_links.txt", 'r') as file:
    # Use readlines() to read the lines of the file into a list
        links = file.readlines()

    init_csv_files()
    #links = links[36:]

    votes = []
    i = 0
    for link in links:
        print(str(i) + ": " + link)
        i += 1
        ayes_ln, noes_ln, header = getVotesAndHeader(link)
        if header != None:
            ayes = getFullNameList(ayes_ln, mps)
            noes = getFullNameList(noes_ln, mps)
            write_vote_to_csv(header, ayes, noes)
        #votes.append({"header": header, "ayes": ayes, "noes": noes})
    
    #print(votes)
