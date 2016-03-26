rm out_text.txt
if [ -n "`ls | grep done`" ] ; then
g++ -o tmpw sem_w.cpp -lpthread
g++ -o tmpr sem_r.cpp -lpthread
touch done
fi
msg=$1
if [ -z "$msg" ] ;then
msg="5"
fi
./tmpw 1 $msg /demo &
./tmpr $msg /demo
