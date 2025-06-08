#include "init.hpp"
#include "And64InlineHook.hpp"
#include "../memory/memory.hpp"
#include <cstdint>

enum class print_types : uint8_t {
	print,
	info,
	warn,
	error
};

using print = std::int64_t(*)(print_types type, const char* fmt, ...);
inline print r_print = nullptr;

void* original_game{ nullptr };
int64_t hook_game(int64_t a1, int64_t a2)
{
	const auto org = *reinterpret_cast<decltype(hook_game)*>(original_game);
	const auto grab = org(a1, a2);

	if (a2)
	{
		r_print(print_types::print, "Hello from Print Exploit!");
	}

	return grab;
}

auto init::start() -> void
{
	__android_log_print(ANDROID_LOG_INFO, "PRINT-CHEAT", "init::start called");

	r_print = reinterpret_cast<decltype(r_print)>(memory::rebaseAddress(0x45B9E30)); // 2.673.1715
	const auto game = reinterpret_cast<void*>(memory::rebaseAddress(0x2666020)); // STILL ON 666 WILL UPDATE LATER

	A64HookFunction(reinterpret_cast<void*>(game), reinterpret_cast<void*>(&hook_game), reinterpret_cast<void**>(&original_game));
}
