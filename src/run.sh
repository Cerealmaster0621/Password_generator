# make Script executable first with
# chmod +x run.sh
# run the program with
# ./run.sh
if [ -f ./main ]; then
    ./main "$@"
else
    g++ --std=c++14 -o main main.cpp engine.constructor.cpp engine.member.cpp

    if [ $? -eq 0 ]; then
        ./main "$@"
    else
        echo "Compilation failed."
    fi
fi
