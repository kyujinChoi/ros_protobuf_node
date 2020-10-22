tail -n 100 /var/log/syslog -F 
echo -e "\n"
ps -axj | grep -E 'main'
#echo -e "\n"
