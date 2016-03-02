from sys import argv
#written by schenning

EMPTY_TILE = '0'

class Shape(object):

    def __init__(self, filename):
        with open(filename, 'r') as f:
            shape_string = f.read().rstrip('\n')
            shape_string = shape_string.replace(' ', EMPTY_TILE)
        self.char = sorted( list([elem for elem in shape_string])).pop()
        self.num_of_characters = shape_string.count(self.char)
        self.shape = shape_string.split('\n')
        self.num_of_rows = len(self.shape)
        self.num_of_columns = len(max(self.shape))


    def iterate(self):
        for row_idx, row in enumerate(self.shape):
            for col_idx, col in enumerate(row):
                yield row_idx, col_idx

class Board(object):

    def __init__(self, size):
        self.size = size
        self.board = [ [EMPTY_TILE]*self.size for x in range(self.size) ]

    def iterate_board(self):
        for row in range(0, self.size):
            for column in range(0, self.size):
                yield (row, column)

    def fits(self, shape, row, column):

        if (shape.num_of_rows + row > self.size or
            shape.num_of_columns + column > self.size):
            return False

        for shape_row, shape_col in shape.iterate():
            if (shape.shape[shape_row][shape_col] != EMPTY_TILE and
                self.board[row+shape_row][column+shape_col] != EMPTY_TILE):
                return False

        return True

    def draw_shape(self, shape, row, column):
        for shape_row, shape_col in shape.iterate():
            if shape.shape[shape_row][shape_col] != EMPTY_TILE:
                self.board[row+shape_row][column+shape_col] = shape.shape[shape_row][shape_col]

    def erase_shape(self, shape):
        for row, column in self.iterate_board():
            if self.board[row][column] == shape.char:
                self.board[row][column] = EMPTY_TILE

    def fill_with_shapes(self, shapes):
        if not shapes:
            return True

        for row, column in self.iterate_board():
            if self.fits(shapes[0], row, column):
                self.draw_shape(shapes[0], row, column)
                if self.fill_with_shapes(shapes[1:]):
                    return True
                self.erase_shape(shapes[0])

        return False

    def writeOut(self):
        for line in self.board:
            print(''.join(line))

if __name__ == '__main__':

    boardSize=0
    shapes = []
    for filename, k in zip(argv[1:], range(len(argv)-1) ):
        shapes.append(Shape(filename))
        boardSize+=shapes[k].num_of_characters
    board = Board(int((boardSize)**(1/2.0)))
    board.fill_with_shapes(shapes)
    board.writeOut()
