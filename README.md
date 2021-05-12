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
- `int Randt(int l, int r, mt19937& rando)`: Return an integer between `l` and `r`, using `rando` as the random number generator.
- `bool HasLegalMove(const Board& board)`: Check if a board has any legal move.
- `bool CanMove(const Board& board, int direction)`: Check if a move in the direction `direction` is valid.
- `class Game`: Class that controls the game.
- `int Game::move`, `int Game::score`, `Board Game::board`: Do I need to tell you what are these?
- `const int Game::MaxMove`, `const int Game::MaxScore`: Same as above. Although `Game::MaxScore` is not actually the maximum score that can be achieved, but just to signal that `Game::move` has exceeded `Game::MaxMove`.
- `Board Init(mt19937& rando)`: Initialize the game. `rando` is used to generate the first two cells.
- `Board Move(int direction, mt19937& rando)`: Move the board in the direction `direction`. `rando` is used to generate a new cell. 

## TODO Lists

- [ ] Change type of `rando` to a class that has `operator()` returns an integer.
- [ ] Change the (generating new cells after making a move) part to a class that has `operator()` returns a valid pair.
- [ ] Make functions that get `move`, `score`, and `board` (should be easy).
- [ ] Related to the second todo, split `Move()` into `Slide()` and then use the generator.
