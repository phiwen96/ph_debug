#pragma once
using namespace std;
#include <ph_time/time.hpp>
#include <ph_color/color.hpp>

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

//[[nodiscard]] auto debug (string called = __builtin_FUNCTION ()) -> _debug {
//    return {move (called)};
//}

#define debug(x) IF_ELSE(x)(auto _##__COUNTER__ = debug (__PRETTY_FUNCTION__))();

#define debug_called_from string _function_line = to_string (__LINE__), string _called_from_function = __builtin_FUNCTION(), int _called_from_line = __builtin_LINE()
#define debug_print_called_from(_color, index) out (index, _color + string (__FUNCTION__) + string ("::") +  _function_line, _color + _called_from_function + "::"  + to_string(_called_from_line)); cout << white;
#define D01(color, index) out(index, text {string (__FUNCTION__) + to_string(__LINE__), string (color)}); cout << white;
#define BWRITE(color, index, ...) for(int _j = 0; _j < index; ++_j)cout << "\t"; cout << white << " B  " << color; cout << BOOST_PP_STRINGIZE (__VA_ARGS__) << endl; cout << white;
#define EWRITE(color, index, ...) for(int _j = 0; _j < index; ++_j)cout << "\t"; cout << cyan << " E  " << color; cout << BOOST_PP_STRINGIZE (__VA_ARGS__) << endl; cout << white;

#define debug_class_print_called_from(_color, index, ...) out (index, string (_color) + class_name + green + "::" + white + string (__FUNCTION__), white + _called_from_function + "::"  + to_string(_called_from_line) __VA_OPT__ (,) __VA_ARGS__); cout << white;
#define debug_called_from_none string _called_from_function = ""; int _called_from_line = 0; int _function_line = 0;


/**
 out (0, "hej", "då", "kiss");
 out (0, "hej", "då");
 */
template <bool endline = true, int mellanrum = 30>
void out (int shiftFirstLeft, auto&& s1, auto&&... s) {
    for(int i = 0; i < shiftFirstLeft; ++i)
    {
        cout << "\t";
    }
    
    
    
//    cout << right << setw(0) << "[" << index << "] " << s << left << "\t" << s2 << endl;
//    cout << s << internal << std::setfill('*') << setw(40) << s2 << "\n";
//    Green b;
    
    cout <<  black << " •  " << white  << left << setw (70) << s1;
//    cout << left << setw (10);
    ((cout << black << " •  " << white << left << setw (30) << s), ...);
    cout << setw (0);
    
    if constexpr (endline)
        cout << endl;
        

//    ((cout << black << " •  " << white << left << setw(60) << s), ...);
    
//    cout << setw(20);
//    cout  <<  setw(30) << s2  << "--" << "\t" << endl;
//    cout << white;
    
    
    
//    SET_COLOR_OR_WHITE(color)
//    cout << format_string(s, "|", s2) << endl;
//         << setw(4) << hourlyRate << "\n";

//    color << "[" << index << "] " << s << setw(20) << s2 << endl;
}


//void out (auto&& s, auto&& s2, int index) {
//    out (white, forward<decltype(s)> (s), forward<decltype(s2)> (s2), index);
//}
