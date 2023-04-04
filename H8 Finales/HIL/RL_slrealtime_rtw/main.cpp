/* Main generated for Simulink Real-Time model RL */
#include <ModelInfo.hpp>
#include <utilities.hpp>
#include "RL.h"

/* Task descriptors */
slrealtime::TaskInfo task_1( 0u, std::bind(RL_step), slrealtime::TaskInfo::PERIODIC, 0.00025, 0, 40);

/* Executable base address for XCP */
#ifdef __linux__
extern char __executable_start;
static uintptr_t const base_address = reinterpret_cast<uintptr_t>(&__executable_start);
#else
/* Set 0 as placeholder, to be parsed later from /proc filesystem */
static uintptr_t const base_address = 0;
#endif

/* Model descriptor */
slrealtime::ModelInfo RL_Info =
{
    "RL",
    RL_initialize,
    RL_terminate,
    []()->char const*& { return RL_M->errorStatus; },
    []()->unsigned char& { return RL_M->Timing.stopRequestedFlag; },
    { task_1 },
    slrealtime::SegmentVector()
};

int main(int argc, char *argv[]) {
    slrealtime::BaseAddress::set(base_address);
    return slrealtime::runModel(argc, argv, RL_Info);
}
