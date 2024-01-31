#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

enum operation
{
    ADD,
    SUBSTRACT,
    SCALE,
    LENGTH,
    NORMALIZE,
    BREAK
};

operation operation_converted (string &operation)
{
    if (operation == "add")
        return ADD;
    else if (operation == "subtract")
        return SUBSTRACT;
    else if (operation == "scale")
        return SCALE;
    else if (operation == "length")
        return LENGTH;
    else if (operation == "normalize")
        return NORMALIZE;
    else
        return BREAK;
}

struct vector_coord
{
    float x = 0.0f;
    float y = 0.0f;
};

float vector_lenght (vector_coord vector_1)
{
    return sqrt(pow(vector_1.x, 2) + pow(vector_1.y, 2));
}

vector_coord vector_scale (vector_coord vector_1, float scale)
{
    //result vector
    vector_coord vector_res;

    vector_res.x = vector_1.x * scale;
    vector_res.y = vector_1.y * scale;

    return vector_res;
}

vector_coord vector_add (vector_coord vector_1, vector_coord vector_2)
{
    //result vector
    vector_coord vector_res;

    vector_res.x = (vector_1.x + vector_2.x);
    vector_res.y = (vector_1.y + vector_2.y);

    return vector_res;
}

vector_coord vector_subtract (vector_coord vector_1, vector_coord vector_2)
{
    //result vector
    vector_coord vector_res;

    vector_res.x = (vector_1.x - vector_2.x);
    vector_res.y = (vector_1.y - vector_2.y);

    return vector_res;
}

vector_coord vector_normalize (vector_coord vector_1)
{
    return vector_scale(vector_1, 1 / vector_lenght(vector_1));
}


int main()
{
    operation command_enum;
    vector_coord vector_1;
    string command;
    bool correct = false;

    while (correct == false)
    {
        cout << "Enter command (add, subtract, scale, length, normalize): ";
        cin >> command;

        command_enum = operation_converted(command);

        if (command_enum != BREAK) correct = true;
    }

    //Vector #1
    cout << "Enter vector_1 coordinate x: ";
    cin >> vector_1.x;
    cout << "Enter vector_1 coordinate y: ";
    cin >> vector_1.y;

    if (command_enum == ADD)
    {
        vector_coord vector_2;
        vector_coord vector_res;

        cout << "Enter vector_2 coordinate x: ";
        cin >> vector_2.x;
        cout << "Enter vector_2 coordinate y :";
        cin >> vector_2.y;

        vector_res = vector_add(vector_1, vector_2);

        cout << "Result: (" << vector_res.x << ", " << vector_res.y << ")";
    }
    else if (command_enum == SUBSTRACT)
    {
        vector_coord vector_2;
        vector_coord vector_res;

        cout << "Enter vector_2 coordinate x: ";
        cin >> vector_2.x;
        cout << "Enter vector_2 coordinate y :";
        cin >> vector_2.y;

        vector_res = vector_subtract(vector_1, vector_2);

        cout << "Result: (" << vector_res.x << ", " << vector_res.y << ")";
    }
    else if (command_enum == SCALE)
    {
        float scale;
        vector_coord vector_res;

        cout << "Enter scale: ";
        cin >> scale;

        vector_res = vector_scale(vector_1, scale);

        cout << "Result: (" << vector_res.x << ", " << vector_res.y << ")";
    }
    else if (command_enum == LENGTH)
    {
        cout << "Result: " << vector_lenght(vector_1);
    }
    else if (command_enum == NORMALIZE)
    {
        vector_coord vector_res;

        vector_res = vector_normalize(vector_1);

        cout << "Result: (" << vector_res.x << ", " << vector_res.y << ")";
    }
}