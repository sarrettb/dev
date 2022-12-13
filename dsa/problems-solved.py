import argparse
import os 
import json

# Parse arguments from command line
parser = argparse.ArgumentParser(description="""Counts numbers of files relative to input directory.\n
                                       Each file corresponds to one DSA problem solved.\n """)
parser.add_argument('--input', '-i', required=True, help="""Specify input file path. Slashes must be replaced with double slashes
                                                          for the parser""")
parser.add_argument('--ignore', '-g', required=False, help='Specify folders to ignore.', nargs='+')
args = parser.parse_args()

# Count the number of files in the folders that should not be ignored 
folders = [folder for folder in next(os.walk(args.input))[1] if folder not in args.ignore]
problems_solved = list() 
for folder in folders:
    path = os.path.join(args.input, folder)
    count = 0
    for _, __, filenames in os.walk(path):
        count += len(filenames)
    problems_solved.append(count)

# Generate dictionary corresponding {folder name : problem solved in that folder} then write it to a json file
output_file_name = os.path.join(args.input, 'problems-solved.json')
my_dict = dict()
for folder_name, file_count in zip(folders, problems_solved):
    if (file_count > 0):
        my_dict[folder_name] = file_count
my_json = json.dumps(my_dict, indent=4)
with open(output_file_name, "w") as output_file:
    output_file.write(my_json)

print(f'Results stored at {output_file_name}')