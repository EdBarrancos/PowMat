import filecmp
import subprocess
import os
from glob import glob


HEADER = '\033[95m'
OKBLUE = '\033[94m'
OKCYAN = '\033[96m'
OKGREEN = '\033[92m'
WARNING = '\033[93m'
FAIL = '\033[91m'
ENDC = '\033[0m'
BOLD = '\033[1m'
UNDERLINE = '\033[4m'


FILES = glob("tests/inputs/*")

names = []

for file in FILES:
    _, name = os.path.split(file)
    names.append(name)
    os.system(f"./bin/powMat <{file} >tests/tmp/{name}")

a = filecmp.cmpfiles("tests/outputs/", "tests/tmp/", names)
print(f"-----------------", f"\n{BOLD}{UNDERLINE}TESTING ./bin/powMat{ENDC}\n")
print(
    f"{OKGREEN}Matches: {a[0]}\n{FAIL}Mismatches: {a[1]}\n{ENDC}Errors: {a[2]}")