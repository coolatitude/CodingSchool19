cat /etc/passwd | awk 'NR > 10' | cut -d':' -f1 -f3 -f6
