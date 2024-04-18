import subprocess

# Read the fixes.txt file
with open("fixes_test.txt", "r") as file:
    lines = file.readlines()

# Loop through each line in fixes.txt
for line in lines:
    # Strip leading and trailing whitespace
    line = line.strip()

    # Check if the line is not empty and does not start with a comment
    if line and not line.startswith("#"):
        print(f"Processing line: {line}")

        # Run the command in minishell
        minishell_process = subprocess.Popen([".././minishell"], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        minishell_stdout, minishell_stderr = minishell_process.communicate(input=f"{line}\necho $?\n")

        # Capture the exit code of minishell
        minishell_exit_code = int(minishell_stdout.split()[-1]) if minishell_stdout else None

        # Run the same command in bash
        bash_process = subprocess.Popen(["bash"], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        bash_stdout, bash_stderr = bash_process.communicate(input=f"{line}\necho $?\n")

        # Capture the exit code of bash
        bash_exit_code = int(bash_stdout.split()[-1]) if bash_stdout else None

        # Split minishell output into words (excluding "minishell: " prefix)
        minishell_words = [word for word in minishell_stdout.split() if word != "minishell:"]

        # Initialize flag for output comparison
        match = True

        # Loop through each word in minishell output
        for word in minishell_words:
            # Check if the word exists in bash output and is not "exit"
            if word != "exit" and word not in bash_stdout.split():
                match = False
                break

        # Print the minishell output
        print("Minishell output:")
        print(minishell_stdout)

        # Print the bash output
        print("Bash output:")
        print(bash_stdout)

        # Compare the outputs
        if match:
            print("\033[32mOutput matches ✓\033[0m")
        else:
            print("\033[31mOutput does not match ✗\033[0m")

        # Compare the exit codes
        if minishell_exit_code is not None and bash_exit_code is not None and minishell_exit_code == bash_exit_code:
            print("\033[32mExit code matches ✓\033[0m")
        else:
            print("\033[31mExit code does not match ✗\033[0m")

        # Print a separator
        print("--------------------------------------------")
