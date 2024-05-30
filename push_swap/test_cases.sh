
if [ "$1" == "" ] || [ "$2" == "" ]
then
    echo "test_cases.sh "Count" "MAX STEPS""
    exit 1
fi

while true
do
    ARG="$(jot -r -s " " $1 -2147483648 2147483647)"
    REZ="$(./push_swap $ARG | wc -l | tr -d ' ')"
    echo "Total moves: $REZ"
    if [ $REZ -gt $2 ]
    then
        echo "Found a Case: $ARG"
    break
    fi
done