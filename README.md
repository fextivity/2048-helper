# 2048-helper
tis a 2048 helper class

## Technical Details

**Tips**:
- You can use `using namespace Helper2048;` to get rid of using `Helper2048::` everywhere.
- If you don't know how to use this helper, reading the [generator](2048_interactor.cpp) or the [model solution](2048_solution.cpp) should help.

**Elements**:
- `N`: Size of the board, must be larger than or equal to 3. It is currently constant (equals 4), but I might change it for future tasks.
- `Board`: Alias/typedef of `array <array <int, N>, N>`.
- `Up`, `Left`, `Down`, `Right`: Constants used to denote directions.
- `bool HasLegalMove(const Board& board)`: Check if a board has any legal move.
- `bool CanMove(const Board& board, int direction)`: Check if a move in the direction `direction` is valid.
- `class Game`: Class that controls the game.
- `int Game::move`, `int Game::score`, `Board Game::board`: Do I need to tell you what are these?
- `const int Game::MaxMove`, `const int Game::MaxScore`: Same as above. Although `Game::MaxScore` is not actually the maximum score that can be achieved, but just to signal that `Game::move` has exceeded `Game::MaxMove`.
- `Game::Game()`: Initialize the class, with `move`, `score` and `board` set to all 0s.
- `Game::Game(int move, int score, const Board& board)`: Initialize the class with given `move`, `score` and `board`.
- `int Game::GetMove()`, `int Game::GetScore()`, `Board Game::GetBoard()`: Return the appropriate data.
- `Board Init(Tgen& gen)`: Initialize the game. `gen` is used to generate the first two cells. `gen` must has `operator(Board& board)` which add a new cell to `board`.
- `Board Move(int direction, Tgen& gen)`: Move the board in the direction `direction`. `gen` is used to generate a new cell. `gen` must has `operator(Board& board)` which add a new cell to `board`.

## TODO Lists

- [x] ~~Change type of `rando` to a class that has `operator()` returns an integer.~~ Turns out that we only need the second bullet point.
- [x] Change the (generating new cells after making a move) part to a class that has `void operator(Board& board)` change the board.
- [x] Make functions that get `move`, `score`, and `board` (should be easy).
- [x] ~~Related to the second bullet point, split `Move()` into `Slide()` and then use the generator.~~ Unusable because Slide does involve computing `move` and `score`.
- [x] ~~Add debug mode.~~ Too hard, because I am a dipshit and also:
  - First I tried to make debug available on both stdout and file, but then two of them mixes together and file need a whole new ofstream so I just scrapped stdout.
  - Track which object has debug or not + do not erase whole content of log file when declare new object + erase old content = fuck off.
- [x] Add initialization with given `move`, `score` and `board`.
