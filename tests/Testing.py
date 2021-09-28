import difflib
import subprocess
import os
from glob import glob


HEADER = '\033[95m'
OKBLUE = '\033[94m'
OKCYAN = '\033[96m'
OKGREEN = '\033[92m'
OKRED = '\033[33m'
WARNING = '\033[93m'
FAIL = '\033[91m'
ENDC = '\033[0m'
BOLD = '\033[1m'
UNDERLINE = '\033[4m'

def PrintFail(arg):
    if arg == False:
        print(f"{OKRED}{BOLD}->TEST FAILED{ENDC}",f"\n-----------------")
    return True

def PrintPass():
    print(f'{OKGREEN}{BOLD}->TEST PASSED{ENDC}',f"\n-----------------")

FILES = glob("tests/inputs/*")

print(f"-----------------", f"\n{BOLD}{UNDERLINE}TESTING ./bin/powMat{ENDC}\n")


for file in FILES:
    _,name = os.path.split(file)
    print(f'{OKBLUE}{name}:{ENDC}')
    os.system(f"./bin/powMat <{file} >tests/tmp/{name}")
    
    output = open(f"tests/outputs/{name}").readlines()
    tmp = open(f"tests/tmp/{name}").readlines()

    thereIsDiff = False
    for line in difflib.unified_diff(output,tmp):
        thereIsDiff = PrintFail(thereIsDiff)
        print(line)
    if not thereIsDiff:
        PrintPass()