from multiprocessing import Pool
import random
import os

iterations = 5
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
    # print(' '.join(input_actions))
    run = os.popen('timeout 30 python3 resolver/main.py "' + ' '.join(input_actions) + '"')
    text = run.read()
    lines = text.splitlines()
    if not lines:
        print('timed out: "' + ' '.join(input_actions) + '"')
        return None
    number_moves = len(lines.pop(0).split(' '))
    if lines != ['      \x1b[103m  \x1b[103m  \x1b[103m  \x1b[49m', '      \x1b[103m  \x1b[103m  \x1b[103m  \x1b[49m', '      \x1b[103m  \x1b[103m  \x1b[103m  \x1b[49m', '\x1b[41m  \x1b[41m  \x1b[41m  \x1b[102m  \x1b[102m  \x1b[102m  \x1b[106m  \x1b[106m  \x1b[106m  \x1b[44m  \x1b[44m  \x1b[44m  \x1b[49m', '\x1b[41m  \x1b[41m  \x1b[41m  \x1b[102m  \x1b[102m  \x1b[102m  \x1b[106m  \x1b[106m  \x1b[106m  \x1b[44m  \x1b[44m  \x1b[44m  \x1b[49m', '\x1b[41m  \x1b[41m  \x1b[41m  \x1b[102m  \x1b[102m  \x1b[102m  \x1b[106m  \x1b[106m  \x1b[106m  \x1b[44m  \x1b[44m  \x1b[44m  \x1b[49m', '      \x1b[107m  \x1b[107m  \x1b[107m  \x1b[49m', '      \x1b[107m  \x1b[107m  \x1b[107m  \x1b[49m', '      \x1b[107m  \x1b[107m  \x1b[107m  \x1b[49m', '']:
        print('error with sequence: "' + ' '.join(input_actions) + '"')
        return None
    return number_moves


def throw_away_function(_):
    return single_test()


if __name__ == '__main__':
    with Pool(5) as p:
        results = p.map_async(throw_away_function, range(iterations))
        p.close()
        p.join()
        print(results.get())
