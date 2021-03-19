//
// Created by Mike Quinn on 3/19/21.
//

#ifndef SIMPLE_GAME_SERIALIZABLE_H
#define SIMPLE_GAME_SERIALIZABLE_H


class Serializable {
public:
    virtual std::ostream &serialize(std::ostream &os) const = 0;
}


#endif //SIMPLE_GAME_SERIALIZABLE_H
