import csv
import argparse

parser = argparse.ArgumentParser(description="dna")
parser.add_argument("database", help= "a csv database")
parser.add_argument("dna_file", help= "a dna file")

args = parser.parse_args()

with open(args.database, "r") as f:
    reader = csv.DictReader(f)
    lst_db = []
    my_row = {}
    for row in reader:
        lst_db.append(row)

with open(args.dna_file, "r") as f:
    dna = f.read().strip("\n")

longest_sequence = 0
up_to_now = {}
for key in list(lst_db[0].keys())[1:]:
    for j in range(len(key)):
        for i in range(0, len(dna), len(key)):
            if i+j+len(key) <= len(dna):
                sequence = dna[i+j:i+j+len(key)]
                if sequence == key:
                    longest_sequence += 1
                    up_to_now[key] = str(longest_sequence)
                else: 
                    longest_sequence = 0

print(up_to_now)
def output(list_of_max, max_in_dna):
    count = 0
    for person in list_of_max:
        for key in max_in_dna.keys():
            if person[key] == max_in_dna[key]:
                count += 1
            else: 
                break
        if count == len(max_in_dna.keys()):
            return person["name"]
    return "No match"

print(output(lst_db, up_to_now))


