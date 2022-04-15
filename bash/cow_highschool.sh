for ((i = 1; i <= $1; i++)); do
    clear
    cowsay $(($i * $i))
    sleep 1
done
