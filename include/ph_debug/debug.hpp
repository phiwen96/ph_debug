#pragma once
using namespace std;
#include <ph_time/time.hpp>


struct _debug {
    string function_name;
    string time_called;
    __thread_id thread_id;
    
    _debug (string&& function_name) : function_name {function_name}, time_called {now ()}, thread_id {this_thread::get_id()} {
//        cout << function_name << " (...) time: " << time_called << " thread: " << thread_id << endl;
    }
    ~_debug () {
        cout << "========================================" << endl;
        cout << function_name << "\n\t time: " << time_called << "~ " << now () << "\n\tthread: " << thread_id << endl;
        cout << "========================================" << endl;
    }
};

[[nodiscard]] auto debug (string called = __builtin_FUNCTION ()) -> _debug {
    return {move (called)};
}

#define debug(x) IF_ELSE(x)(auto _##__COUNTER__ = debug (__PRETTY_FUNCTION__))();
