
#include "afe_session.hpp"
#include <iostream>

// Constructor
bms::AfeSession::AfeSession()
{
    std::cout << "AFE session opened\n";
}

// Destructor
bms::AfeSession::~AfeSession()
{
    std::cout << "AFE session closed\n";
}
