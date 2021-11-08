import argparse

from cube import Cube, Moves
from algorythm import solve
import config

ap = argparse.ArgumentParser()
ap.add_argument('-v', '--verbose', required=False, default=False, action='store_true')
ap.add_argument('-s', '--size', required=False, default=3)
ap.add_argument('-t', '--tester', required=False, default=False, action='store_true')
ap.add_argument('moves', metavar='M', type=str,
                help='the list of the moves to apply')

args = vars(ap.parse_args())

config.verbose = args['verbose']
config.tester = args['tester']


def main():
    cube = Cube(args['size'])
    if config.verbose:
        cube.print()
    for move in args['moves'].split(' '):
        cube.do_move(move)
        if config.verbose:
            cube.print()
    solve(cube)
    cube.print_moves()
    if config.tester:
        cube.print()


main()
