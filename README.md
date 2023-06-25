# gameloop-pattern-cpp
Game loop pattern &amp; small example

Something similar to https://gameprogrammingpatterns.com/game-loop.html.

For accurate calculation of processor ticks, it is better to use another method, not GetTickCount. 
```cpp
long long GetCPUTicks(){
  return GetTickCount() * 10000i64;
}
```
Const `10000i64` for normalize ticks.

User input can be written in a separate function and called before the update:
```cpp
if (time.IsRequiredGameUpdate()){
  //GetUserInput();
  Update(time.Ticks.Current);
  ...
}
```
Or in the update function: 
```cpp
void Update(long long time) override {
  //GetUserInput();
}
```

# Usage:
Create a class, inherit it from the GameLoop:
```cpp
class GameSample : public GameCore::GameLoop
{
private:
...
public:
	void Update(long long time) override;
	void Render() override;
};
```
Next - configure it and run:
```cpp
auto game = GameSample(...);
game.Run();
```

Update method will be called ~60 times per second, Render will be called as many times as performance allows.
