	#!/bin/sh
echo "REMEMBER TO CHECK FOR MEMORY LEAKS AND ADD CHECK IF ST->STACKB IS EMPTY TO CHECKIFSORTED"

echo "Running test"

ARG="2 1 0"
push=$(./push_swap $ARG | wc -l)
push_check=$(./push_swap $ARG | ./checker $ARG)
printf "%-40s avg:%s status: %s\n" "Simple instruction count (< 4)" "$push" "$push_check"

ARG="1 5 2 4 3"
push=$(./push_swap $ARG | wc -l)
push_check=$(./push_swap $ARG | ./checker $ARG)
printf "%-40s avg:%s status: %s\n" "Simple2 instruction count (< 13)" "$push" "$push_check"

ARG=$(python3 rand_nums.py -20 20 5)
push=$(./push_swap $ARG | wc -l)
push_check=$(./push_swap $ARG | ./checker $ARG)
printf "%-40s avg:%s status: %s\n" "Random Simple instruction count (< 13)" "$push" "$push_check"

ARG=$(python3 rand_nums.py -100 100 100)
push=$(./push_swap $ARG | wc -l)
push_check=$(./push_swap $ARG | ./checker $ARG)
printf "%-40s avg:%s status: %s\n" "Middle instruction count (< 700)" "$push" "$push_check"

ARG=$(python3 rand_nums.py -500 500 500)
push=$(./push_swap $ARG | wc -l)
push_check=$(./push_swap $ARG | ./checker $ARG)
printf "%-40s avg:%s status: %s\n" "Advanced instruction count (< 5500)" "$push" "$push_check"

result='All test passed!'
for i in {1..100}
do
	ARG=$(python3 rand_nums.py -20 20 5)
	# echo $ARG
	push=$(./push_swap $ARG | wc -l)
	push_check=$(./push_swap $ARG | ./checker $ARG)
	if [ $push -ge 13 ]
	then
		printf "%-30s %s\n" "Arg: $ARG" "count: $push"
		result=''
	fi
done
printf "$result"