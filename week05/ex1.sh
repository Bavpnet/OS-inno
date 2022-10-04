gcc publisher.c -o publisher
gcc subscriber.c -o subscriber
n=$1
for i  in $(seq 1 $n); do
gnome-terminal -- ./subscriber &
done
./publisher $n