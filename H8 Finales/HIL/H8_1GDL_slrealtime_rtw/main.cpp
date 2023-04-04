/* Main generated for Simulink Real-Time model H8_1GDL */
#include <ModelInfo.hpp>
#include <utilities.hpp>
#include "H8_1GDL.h"

/* Task descriptors */
slrealtime::TaskInfo task_1( 0u, std::bind(H8_1GDL_step0), slrealtime::TaskInfo::PERIODIC, 0.00025, 0, 40);
slrealtime::TaskInfo task_2( 1u, std::bind(H8_1GDL_step2), slrealtime::TaskInfo::PERIODIC, 0.0005, 0, 39);
slrealtime::TaskInfo task_3( 2u, std::bind(H8_1GDL_step3), slrealtime::TaskInfo::PERIODIC, 0.001, 0, 38);

/* Executable base address for XCP */
#ifdef __linux__
extern char __executable_start;
static uintptr_t const base_address = reinterpret_cast<uintptr_t>(&__executable_start);
#else
/* Set 0 as placeholder, to be parsed later from /proc filesystem */
static uintptr_t const base_address = 0;
#endif

/* Model descriptor */
slrealtime::ModelInfo H8_1GDL_Info =
{
    "H8_1GDL",
    H8_1GDL_initialize,
    H8_1GDL_terminate,
    []()->char const*& { return H8_1GDL_M->errorStatus; },
    []()->unsigned char& { return H8_1GDL_M->Timing.stopRequestedFlag; },
    { task_1, task_2, task_3 },
    slrealtime::SegmentVector()
};

int main(int argc, char *argv[]) {
    slrealtime::BaseAddress::set(base_address);
    return slrealtime::runModel(argc, argv, H8_1GDL_Info);
}
