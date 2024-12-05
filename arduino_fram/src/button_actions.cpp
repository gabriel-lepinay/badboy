#include "engine.hpp"

void go_down(EngineManager &engine) {
    engine.Led.set_color(255, 0, 255);

    if (engine.cur_i == engine.scripts.size() - 1) {
        engine.cur_i = 0;
        engine.display_scripts();
    } else {
        engine.cur_i++;
        engine.display_scripts();
    }
    engine.Led.set_color(0, 255, 0);
}

void go_up(EngineManager &engine) {
    engine.Led.set_color(255, 0, 255);
    
    if (engine.cur_i <= 0) {
        engine.cur_i = engine.scripts.size() - 1;
        engine.display_scripts();
    } else {
        engine.cur_i--;
        engine.display_scripts();
    }
    engine.Led.set_color(0, 255, 0);
}

void select_script(EngineManager &engine) {
    engine.Led.set_color(0, 0, 255);
    engine.Sd.exec_script(engine.scripts[engine.cur_i]);
    engine.Led.set_color(0, 255, 0);
}