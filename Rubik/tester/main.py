from multiprocessing import Pool
import random
import os

iterations = 2
min_actions = 5
max_actions = 20

actions = [
    'F2',
    'R2',
    'U2',
    'B2',
    'L2',
    'D2',
    'F',
    'R',
    'U',
    'B',
    'L',
    'D',
    'F\'',
    'R\'',
    'U\'',
    'B\'',
    'L\'',
    'D\''
]


def single_test():
    number_actions = random.randint(min_actions, max_actions)
    input_actions = [random.choice(actions) for x in range(number_actions)]
    run = os.popen('timeout 30 python3 resolver/main.py "' + ' '.join(input_actions) + '"')
    text = run.read()
    lines = text.splitlines()
    if not lines:
        print('timed out: "' + ' '.join(input_actions) + '"')
        return None
    number_moves = len(lines.pop(0).split(' '))
    if lines != ['      \x1b[103m  \x1b[103m  \x1b[103m  \x1b[49m', '      \x1b[103m  \x1b[103m  \x1b[103m  \x1b[49m', '      \x1b[103m  \x1b[103m  \x1b[103m  \x1b[49m', '\x1b[41m  \x1b[41m  \x1b[41m  \x1b[102m  \x1b[102m  \x1b[102m  \x1b[106m  \x1b[106m  \x1b[106m  \x1b[44m  \x1b[44m  \x1b[44m  \x1b[49m', '\x1b[41m  \x1b[41m  \x1b[41m  \x1b[102m  \x1b[102m  \x1b[102m  \x1b[106m  \x1b[106m  \x1b[106m  \x1b[44m  \x1b[44m  \x1b[44m  \x1b[49m', '\x1b[41m  \x1b[41m  \x1b[41m  \x1b[102m  \x1b[102m  \x1b[102m  \x1b[106m  \x1b[106m  \x1b[106m  \x1b[44m  \x1b[44m  \x1b[44m  \x1b[49m', '      \x1b[107m  \x1b[107m  \x1b[107m  \x1b[49m', '      \x1b[107m  \x1b[107m  \x1b[107m  \x1b[49m', '      \x1b[107m  \x1b[107m  \x1b[107m  \x1b[49m', '']:
        print(lines)
        print('error with sequence: "' + ' '.join(input_actions) + '"')
        return None
    return number_moves


def throw_away_function(_):
    return single_test()


if __name__ == '__main__':
    print('Start of the programs')
    with Pool(10) as p:
        results = p.map_async(throw_away_function, range(iterations))
        p.close()
        p.join()
        print(results.get())
'''
timed out: "R2 F' U' D2 D U2 D L' L2 D2 F' B2 B2"
timed out: "L L U' L' F U' L2 U2 D' L L' L F2 L' B L U R U' R"
timed out: "U D R' L' D' U' F' U' R L' L2 B2 L2"
timed out: "R B' R' D B"
'''