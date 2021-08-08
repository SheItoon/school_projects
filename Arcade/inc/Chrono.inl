/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Chrono.inl
*/

inline arc::Chrono::Chrono() :
    m_isRuning(false)
{}

inline arc::Chrono::Chrono(ctorState state) :
    m_isRuning(false)
{
    if (state == Lauch) {
        m_isRuning = true;
        start();
    }
}

inline void arc::Chrono::start()
{
    m_start = std::chrono::steady_clock::now();
    m_end = m_start;
    m_tour = m_start;
    m_isRuning = true;
}

inline void arc::Chrono::stop()
{
    m_end = std::chrono::steady_clock::now();
    m_isRuning = false;
}

inline void arc::Chrono::tour()
{
    m_tour = m_end;
}

inline double arc::Chrono::getElapsedTime()
{
    if (m_isRuning)
        m_end = std::chrono::steady_clock::now();
    double step = std::chrono::duration_cast<std::chrono::milliseconds>(m_end - m_tour).count();
    return (step / 1000);
}

inline double arc::Chrono::getTotalTime()
{
    if (m_isRuning)
        m_end = std::chrono::steady_clock::now();
    double step = std::chrono::duration_cast<std::chrono::milliseconds>(m_end - m_start).count();
    return (step / 1000);
}