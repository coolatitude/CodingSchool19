with open('output.txt', 'w') as f:
    input = open("Moves.csv", "r", encoding="utf-8-sig")
    print('[', file=f)
    x = 0
    for line in input.readlines():
        if x > 53:
            break
        line = line[0: -4]
        print(str([(1 if i == '1' else 0) for i in line.split(';')]))
        print('    ' + str([1 if i == '1' else 0 for i in line.split(';')]) + (',' if x < 53 else ''), file=f)
        x += 1
    input.close()
    print(']', file=f)
    f.close()
