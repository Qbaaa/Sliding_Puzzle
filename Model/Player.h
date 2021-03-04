#ifndef PLAYER_H
#define PLAYER_H

class Player {

protected:
    int movies;
    int time;

public:
    Player();
    ~Player();

    int getMovies() const;
    int getTime() const;

    virtual void move() = 0;

    bool checkCorrectMove();
};

#endif // PLAYER_H
