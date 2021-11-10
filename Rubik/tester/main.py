from multiprocessing import Pool
import random
import os
import statistics

iterations = 200
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


def single_test(_):
    number_actions = random.randint(min_actions, max_actions)
    input_actions = [random.choice(actions) for x in range(number_actions)]
    run = os.popen('timeout 30 python3 resolver/main.py --tester "' + ' '.join(input_actions) + '"')
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


if __name__ == '__main__':
    print('Start of the programs')
    with Pool(25) as p:
        results = p.map_async(single_test, range(iterations))
        p.close()
        p.join()
        result_list = results.get()
        print(results.get())
        print('failed: ' + str(result_list.count(None)))
        print('suceeded: ' + str(len(result_list) - result_list.count(None)))
        filtered_results = filter(lambda x: x is not None, result_list)
        print('mean: ' + str(round(statistics.geometric_mean(filtered_results))))
