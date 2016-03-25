rm out_text.txt
if [ -n "`ls | grep done`" ] ; then
g++ -o tmpw sem_w.cpp -lpthread
g++ -o tmpr sem_r.cpp -lpthread
touch done
fi
./tmpw 1 $1 /demo &
./tmpr $1 /demo
