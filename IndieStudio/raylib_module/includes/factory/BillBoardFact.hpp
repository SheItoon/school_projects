/*
** EPITECH PROJECT, 2021
** BillBoardFact.h
** File description:
** BillBoardFact.h
*/

#ifndef BILLBOARDFACT_H
#define BILLBOARDFACT_H

#include "SW/Factory.hpp"

namespace ray
{
    class BillBoard;

    class BillBoardFact : public sw::AFactory<BillBoard>
    {
        public:
            using AFactory<BillBoard>::AFactory;
            void onLoad() override {};
            void onUpdate() override;
            void onUnload() override {};
    }; // class BillBoardFact

} // namespace ray

#endif //BILLBOARDFACT_H
