/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Chrono.inl
*/

inline sw::Chrono::Chrono() :
    m_isRuning(false)
{}

inline sw::Chrono::Chrono(ctorState state) :
    m_isRuning(false)
{
    if (state == Lauch) {
        m_isRuning = true;
        start();
    }
}

inline void sw::Chrono::start()
{
    m_start = std::chrono::steady_clock::now();
    m_end = m_start;
    m_tour = m_start;
    m_isRuning = true;
}

inline void sw::Chrono::stop()
{
    m_end = std::chrono::steady_clock::now();
    m_isRuning = false;
}

inline void sw::Chrono::tour()
{
    m_tour = m_end;
}

inline double sw::Chrono::getElapsedTime()
{
    if (m_isRuning)
        m_end = std::chrono::steady_clock::now();
    double step = std::chrono::duration_cast<std::chrono::milliseconds>(m_end - m_tour).count();
    return (step / 1000);
}

inline double sw::Chrono::getTotalTime()
{
    if (m_isRuning)
        m_end = std::chrono::steady_clock::now();
    double step = std::chrono::duration_cast<std::chrono::milliseconds>(m_end - m_start).count();
    return (step / 1000);
}

inline bool sw::Chrono::isRunning() const
{
    return (m_isRuning);
}