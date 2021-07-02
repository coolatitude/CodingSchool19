from cube import Cube, Faces, Moves

color_left = 0
color_right = 0
color_down = 0
color_up = 0
color_front = 0
color_back = 0


def do_bottom_cross(cube: Cube):

    def bring_edge_here(match_color, place):
        position_found = -1
        color_match = -1
        for key in cube.edges.keys():
            if cube.grid[key] == color_front and match_color == cube.grid[cube.edges[key]]:
                position_found = key
                color_match = cube.grid[cube.edges[key]]
                break
        # in face B
        # TODO test this one
        back_order = [50, 46, 48, 52]
        if position_found in back_order:
            up_down_match = {
                19: 46,
                21: 50,
                25: 52,
                23: 48
            }[place]
            for x in range((back_order.index(up_down_match) + 4 - back_order.index(position_found)) % 4):
                cube.add_move(Moves.B)
            cube.add_moves({
                19: [Moves.U * 2],
                21: [Moves.R * 2],
                25: [Moves.D * 2],
                23: [Moves.L * 2]
            }[place])
        # in face B inverted (front color not in on B)
        if cube.edges[position_found] in back_order:
            up_down_match = {
                19: 46,
                21: 50,
                25: 52,
                23: 48
            }[place]
            for x in range((back_order.index(up_down_match) + 4 - back_order.index(cube.edges[position_found])) % 4):
                cube.add_move(Moves.B)
            cube.add_moves({
                19: [Moves.U, Moves.F, Moves.BR, Moves.BF],
                21: [Moves.R, Moves.F, Moves.BD, Moves.BF],
                25: [Moves.D, Moves.F, Moves.BL, Moves.BF],
                23: [Moves.L, Moves.F, Moves.BU, Moves.BF]
            }[place])
        # in the front face already but not at the correct position
        front_order = [19, 21, 25, 23]
        if position_found in front_order:
            cube.add_move({
                19: Moves.U,
                21: Moves.R,
                25: Moves.D,
                23: Moves.L
            }[position_found])
            bring_edge_here(match_color, place)
        # in the front face already but not at the correct orientation
        if cube.edges[position_found] in front_order:
            cube.add_move({
                19: Moves.U,
                21: Moves.R,
                25: Moves.D,
                23: Moves.L
            }[cube.edges[position_found]])
            bring_edge_here(match_color, place)
        # in the rest of the places at the level of the second ring
        ring_order = [1, 12, 43, 32]
        if position_found in ring_order:
            count = 0
            expected_places = {
                19: 1,
                21: 12,
                25: 43,
                23: 32
            }
            expected_place = expected_places[place]
            while not (cube.grid[expected_place] == color_front and cube.grid[cube.edges[expected_place]] == color_match):
                count += 1
                cube.add_move(Moves.B2)
                cube.do_moves()
            cube.add_move({
                              19: Moves.BU,
                              21: Moves.BR,
                              25: Moves.BD,
                              23: Moves.BL
                          }[place])
            while count < 4:
                count += 1
                cube.add_move(Moves.B2)
        if cube.edges[position_found] in ring_order:
            count = 0
            expected_places = {
                19: 37,
                21: 30,
                25: 7,
                23: 14
            }
            expected_place = expected_places[place]
            while not (cube.grid[expected_place] == color_front and cube.grid[cube.edges[expected_place]] == color_match):
                count += 1
                cube.add_move(Moves.B2)
                cube.do_moves()
            cube.add_move({
                              19: Moves.U,
                              21: Moves.R,
                              25: Moves.D,
                              23: Moves.L
                          }[place])
            while count < 4:
                count += 1
                cube.add_move(Moves.B2)
        cube.do_moves()

    if not (cube.grid[19] == color_front and cube.grid[16] == color_up):
        bring_edge_here(color_up, 19)
    if not (cube.grid[21] == color_front and cube.grid[41] == color_right):
        bring_edge_here(color_right, 21)
    if not (cube.grid[25] == color_front and cube.grid[28] == color_down):
        bring_edge_here(color_down, 25)
    if not (cube.grid[23] == color_front and cube.grid[3] == color_left):
        bring_edge_here(color_left, 23)


def do_face(cube: Cube):
    pass


def do_second_level(cube: Cube):
    pass


def do_top_cross(cube: Cube):
    pass


def do_corners(cube: Cube):
    pass


def init_faces_color(cube: Cube):
    global color_back, color_up, color_left, color_front, color_down, color_right

    color_left = cube.grid[4]
    color_right = cube.grid[40]
    color_down = cube.grid[31]
    color_up = cube.grid[13]
    color_front = cube.grid[22]
    color_back = cube.grid[49]


def do_bottom_corners(cube: Cube):

    def bring_corner_here(place, match_color1, match_color2):
        found_place = -1
        for corner in cube.corners:
            if cube.grid[corner[0]] == color_front and cube.grid[corner[1]] == match_color1 and cube.grid[corner[2]] == match_color2:
                found_place = corner[0]
                break
            elif cube.grid[corner[1]] == color_front and cube.grid[corner[2]] == match_color1 and cube.grid[corner[0]] == match_color2:
                found_place = corner[1]
                break
            elif cube.grid[corner[2]] == color_front and cube.grid[corner[0]] == match_color1 and cube.grid[corner[1]] == match_color2:
                found_place = corner[2]
                break
        if found_place == -1:
            print('error')
            return
        print('place')
        print(place)
        print(found_place)
        a = [45, 47, 53, 51]
        b = [38, 35, 6, 9]
        c = [44, 33, 0, 11]
        # else
        if found_place in b:
            matching_place = {
                18: 9,
                20: 38,
                26: 35,
                24: 6
            }
            m = matching_place[place]
            while cube.grid[m] != color_front:
                cube.add_move(Moves.B)
                cube.do_moves()
            cube.add_moves({
                18: [Moves.L, Moves.BU, Moves.BL, Moves.U],
                20: [Moves.U, Moves.BR, Moves.BU, Moves.R],
                26: [Moves.R, Moves.BB, Moves.BR, Moves.B],
                24: [Moves.B, Moves.BL, Moves.BB, Moves.L]
            }[place])
        elif found_place in c:
            matching_place = {
                18: 0,
                20: 11,
                26: 44,
                24: 33
            }
            m = matching_place[place]
            while cube.grid[m] != color_front:
                cube.add_move(Moves.B)
                cube.do_moves()
            cube.add_moves({
                18: [Moves.BU, Moves.L, Moves.U, Moves.BL],
                20: [Moves.BR, Moves.U, Moves.R, Moves.BU],
                26: [Moves.BB, Moves.R, Moves.B, Moves.BR],
                24: [Moves.BL, Moves.B, Moves.L, Moves.BB]
            }[place])
        cube.do_moves()


    places = [
        (cube.corners[0], color_left, color_up),
        (cube.corners[1], color_up, color_right),
        (cube.corners[2], color_right, color_down),
        (cube.corners[3], color_down, color_left)
    ]

    for place in places:
        if not (cube.grid[place[0][0]] == color_front and cube.grid[place[0][1]] == place[1] and cube.grid[place[0][2]] == place[2]):
            pass
            bring_corner_here(place[0][0], place[1], place[2])


def solve(cube: Cube):
    init_faces_color(cube)
    print('Solving in progress................................................................')
    cube.print()
    do_bottom_cross(cube)
    print('Cross done.........................................................................')
    do_bottom_corners(cube)

