while true
do
echo "---------------------------------" >> /tmp/mem_usage
date >> /tmp/mem_usage
ps aux | grep "doom-nukem" >> /tmp/mem_usage
sleep 10
done
