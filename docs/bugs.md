- [ x ] 2. [function] [fixed] Pressed `q` button, can't exit.
=> Using `Esc` button insteal.

- [ ] 1. [crash] [unsolved] After press escape, the `glfwTerminate` called and output a Segmentation fault (core dumped).
=> 
In `Game::~Game()` method, `delete Renderer` cause this error.