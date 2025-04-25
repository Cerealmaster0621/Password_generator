# make Script executable first with
# chmod +x run.sh
# run the program with
# ./run.sh

# ANSI escape sequences for colors
RED="\033[0;31m"
GREEN="\033[0;32m"
YELLOW="\033[0;33m"
RESET="\033[0m"

# Array of source files
SOURCE_FILES=("main.cpp" "engine.constructor.cpp" "engine.member.cpp" "time.cpp")

echo -e "${YELLOW}Checking for executable...${RESET}"

if [ -f ./main ]; then
    echo -e "${GREEN}Found existing executable. Running...${RESET}"
    ./main "$@"
else
    echo -e "${YELLOW}No executable found. Compiling...${RESET}"
    
    # Command substitution (meaningless usage)
    COMPILE_TIME=$(date "+%H:%M:%S")
    
    # Using for loop to build compilation command
    COMPILE_CMD="g++ --std=c++14 -o main"
    for src_file in "${SOURCE_FILES[@]}"; do
        COMPILE_CMD="${COMPILE_CMD} ${src_file}"
    done
    
    echo "Compiling at time: ${COMPILE_TIME}"
    eval $COMPILE_CMD

    if [ $? -eq 0 ]; then
        echo -e "${GREEN}Compilation succeeded. Running...${RESET}"
        ./main "$@"
    else
        echo -e "${RED}Compilation failed at $(date "+%H:%M:%S").${RESET}"
    fi
fi
