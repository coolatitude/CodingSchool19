import argparse

from cube import Cube, Moves
from algorythm import solve
import config

ap = argparse.ArgumentParser()
ap.add_argument('-v', '--verbose', required=False, default=False, action='store_true', help="Tells when a step of the algorithm is done")
ap.add_argument('-t', '--tester', required=False, default=False, action='store_true', help="Print the cube at the end of the resolution for the testing program")
ap.add_argument('-c', '--clean', required=False, default=1, choices=[0, 1, 2], type=int, help="Change the level of cleaning of the list of the moves")
ap.add_argument('moves', metavar='M', type=str,
                help='the list of the moves to apply')

args = vars(ap.parse_args())

config.verbose = args['verbose']
config.tester = args['tester']
config.cleaning_level = args['clean']


def main():
    cube = Cube(3)
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
