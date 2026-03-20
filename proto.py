import sys
from os import system, popen

class Profile():
    alias = None
    name = None
    email = None
    def __init__(self, alias, name, email):
        self.alias = alias
        self.name = name
        self.email = email
    
    def print_info(self):
        print(f"{self.alias}, {self.name}, {self.email}")

with open("./profiles.ini", "r") as file:
    lines = file.readlines()

profiles = []

new_alias = None
new_name = None
new_email = None
current_profile = Profile(None, None, None)

for line in lines:
    line = line.strip()

    if (len(line) < 2):
        continue

    if new_alias == None and line[0] == "[":
        new_alias = line.replace("[", "").replace("]", "").replace("\n", "")
        
    if new_name == None and line.split("=")[0].strip() == "name":
        new_name = line.split("=")[1].strip().replace("\"", "").replace("\'", "")

    if new_email == None and line.split("=")[0].strip() == "email":
        new_email = line.split("=")[1].strip().replace("\"", "").replace("\'", "")

    if new_alias != None and new_name != None and new_email != None:
        profiles.append(Profile(new_alias, new_name, new_email))
        new_alias = None
        new_name = None
        new_email = None

args = sys.argv
name = popen("git config get user.name").read().strip()
email = popen("git config get user.email").read().strip()

current_profile = None
for profile in profiles:
    if current_profile == None and profile.name == name and profile.email == email:
        current_profile = profile.alias

if args[1] == "status":
    for profile in profiles:
        if profile.name == name and profile.email == email:
            print(f"Profile: {profile.alias}\nUsername: {name}\nEmail: {email}");

elif args[1] == "switch":
    for profile in profiles:
        if profile.alias == args[2] and current_profile != args[2]:
            system(f"git config --global user.name \"{profile.name}\"")
            system(f"git config --global user.email \"{profile.email}\"")
            print(f"Switched from {current_profile} to {profile.alias}")
            exit(0)

    print(f"Already on {current_profile}")
    exit(0)

        
