// Helper functions for music

#include <cs50.h>
#include<math.h>
#include<string.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    if (fraction[2] == '8')
    {
        return atoi(&fraction[0]);
    }
    else if (fraction[2] == '4')
    {
        return atoi(&fraction[0]) * 2;
    }
    else if(fraction[2] == '2')
    {
        return atoi(&fraction[0]) * 4;
    }
    else
    {
        return atoi(&fraction[0]) * 8;
    }
    return 0;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    float f = 0.0;

    //First getting the note
    if(note[0] == 'A')
    {
        f = 440.0;
    }
    else if (note[0] == 'B')
    {
        f = 440.0 * (pow(2.0, (1.0 / 6.0))); // 2/12 is 1/6
    }
    else if (note[0] == 'C')
    {
        f = 440.0 / (pow(2.0, (3.0 / 4.0))); // 9/12 is 3/4
    }
    else if (note[0] == 'D')
    {
        f = 440.0 / (pow(2.0, (7.0 / 12.0)));
    }
    else if (note[0] == 'E')
    {
        f = 440.0 / (pow(2.0, (5.0 / 12.0)));
    }
    else if (note[0] == 'F')
    {
        f = 440.0 / (pow(2.0, (1.0 / 3.0))); // 4/12 is 1/3
    }
    else if (note[0] == 'G')
    {
        f = 440.0 / (pow(2.0, (1.0 / 6.0))); // 2/12 is 1/6
    }

    //Now getting the accidentals
    if (strlen(note) == 3)
    {
        if (note[1] == '#')
        {
            f = f * (pow(2.0, (1.0 / 12.0)));
        }
        else if (note[1] == 'b')
        {
            f = f / (pow(2.0, (1.0 / 12.0)));
        }
    }

    //Now getting the octave
    int a = strlen(note) - 1;
    if (atoi(&note[a]) > 4)
    {
        for (int i = 4; i < atoi(&note[a]); i++)
        {
            f *= 2.0;
        }
    }
    else if (atoi(&note[a]) < 4)
    {
        for (int i = atoi(&note[a]); i < 4; i++)
        {
            f /= 2.0;
        }
    }
    return round(f);
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strlen(s) == 0)
    {
        return true;
    }
    return false;
}