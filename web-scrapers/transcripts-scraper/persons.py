import csv

if __name__ == "__main__":  
    

# Open the CSV file for reading
    with open('mp.csv', 'r', encoding="utf-8") as csvfile:
    # Create a CSV reader object
        csvreader = csv.reader(csvfile)
    
    # Find the index of the "contact" column
        header = next(csvreader)  # Read the header row
        contact_column_index = header.index('Contact')
    
    # Extract the "contact" column data as a list
        mps = [row[contact_column_index] for row in csvreader]

    for m in range(len(mps)):
        parts = mps[m].split(",")
        mps[m] = parts[1].strip() + " " + parts[0].strip()

    file_path = 'persons.txt'

    # Open the file in read mode
    with open(file_path, 'r', encoding="utf-8") as file:
        content = file.read()

    # Convert the content to a list
    persons = content.splitlines()

    mps_true = []
    mps_false = []

    mps_lower = [name.lower() for name in mps]

    for person in persons:
        if person.lower() in mps_lower:
            mps_true.append(person)
        else:
            mps_false.append(person)
    
    for mp in mps:
        if mp not in mps_true:
            mps_true.append(mp)

    

    with open("persons.csv", mode='w', newline='', encoding="utf-8") as file:
        csv_writer = csv.writer(file)
        csv_writer.writerow(['Name', 'Is_Mp'])
        for person in mps_true:
            csv_writer.writerow([person, True])
        for person in mps_false:
            csv_writer.writerow([person, False])