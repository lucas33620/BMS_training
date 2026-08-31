#pragma once

namespace bms
{
    class AfeSession
    {
    public:
        AfeSession(); // Constructor
        ~AfeSession(); // Destructor

        AfeSession(const AfeSession&) = delete; // Forbid copy construction AfeSession session2(session1);
        AfeSession& operator=(const AfeSession&) = delete; // Forbid copy assignment session2 = session1;
    };

} // namespace bms
