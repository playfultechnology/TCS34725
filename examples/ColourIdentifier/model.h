#pragma once
#include <cstdarg>
namespace Eloquent {
    namespace ML {
        namespace Port {
            class RandomForest {
                public:
                    /**
                    * Predict class for features vector
                    */
                    int predict(float *x) {
                        uint8_t votes[6] = { 0 };
                        // tree #1
                        if (x[0] <= 6.0) {
                            votes[0] += 1;
                        }

                        else {
                            if (x[1] <= 17.5) {
                                if (x[3] <= 169.0) {
                                    if (x[3] <= 131.5) {
                                        if (x[1] <= 13.5) {
                                            votes[4] += 1;
                                        }

                                        else {
                                            if (x[0] <= 23.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[5] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        votes[2] += 1;
                                    }
                                }

                                else {
                                    if (x[2] <= 6.5) {
                                        votes[3] += 1;
                                    }

                                    else {
                                        votes[4] += 1;
                                    }
                                }
                            }

                            else {
                                if (x[1] <= 30.5) {
                                    votes[5] += 1;
                                }

                                else {
                                    if (x[2] <= 3.5) {
                                        if (x[1] <= 32.5) {
                                            if (x[3] <= 286.0) {
                                                votes[5] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }

                                        else {
                                            votes[5] += 1;
                                        }
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }
                        }

                        // tree #2
                        if (x[1] <= 17.5) {
                            if (x[2] <= 7.5) {
                                if (x[0] <= 51.5) {
                                    if (x[0] <= 44.0) {
                                        votes[2] += 1;
                                    }

                                    else {
                                        if (x[0] <= 50.5) {
                                            votes[3] += 1;
                                        }

                                        else {
                                            if (x[3] <= 431.0) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                votes[3] += 1;
                                            }
                                        }
                                    }
                                }

                                else {
                                    votes[3] += 1;
                                }
                            }

                            else {
                                if (x[0] <= 17.5) {
                                    votes[0] += 1;
                                }

                                else {
                                    votes[4] += 1;
                                }
                            }
                        }

                        else {
                            if (x[2] <= 14.0) {
                                if (x[1] <= 29.0) {
                                    votes[5] += 1;
                                }

                                else {
                                    if (x[0] <= 18.0) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[5] += 1;
                                    }
                                }
                            }

                            else {
                                votes[0] += 1;
                            }
                        }

                        // tree #3
                        if (x[1] <= 17.5) {
                            if (x[3] <= 172.0) {
                                if (x[3] <= 108.0) {
                                    votes[4] += 1;
                                }

                                else {
                                    votes[2] += 1;
                                }
                            }

                            else {
                                if (x[0] <= 47.5) {
                                    votes[4] += 1;
                                }

                                else {
                                    votes[3] += 1;
                                }
                            }
                        }

                        else {
                            if (x[0] <= 17.5) {
                                if (x[2] <= 14.0) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }

                            else {
                                votes[5] += 1;
                            }
                        }

                        // tree #4
                        if (x[2] <= 8.5) {
                            if (x[1] <= 17.5) {
                                if (x[3] <= 223.5) {
                                    if (x[2] <= 2.5) {
                                        votes[5] += 1;
                                    }

                                    else {
                                        votes[2] += 1;
                                    }
                                }

                                else {
                                    votes[3] += 1;
                                }
                            }

                            else {
                                if (x[0] <= 18.0) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[5] += 1;
                                }
                            }
                        }

                        else {
                            if (x[1] <= 13.5) {
                                votes[4] += 1;
                            }

                            else {
                                votes[0] += 1;
                            }
                        }

                        // tree #5
                        if (x[0] <= 17.0) {
                            if (x[2] <= 10.0) {
                                votes[1] += 1;
                            }

                            else {
                                votes[0] += 1;
                            }
                        }

                        else {
                            if (x[2] <= 7.5) {
                                if (x[1] <= 18.5) {
                                    if (x[3] <= 232.0) {
                                        if (x[3] <= 131.0) {
                                            votes[5] += 1;
                                        }

                                        else {
                                            votes[2] += 1;
                                        }
                                    }

                                    else {
                                        votes[3] += 1;
                                    }
                                }

                                else {
                                    votes[5] += 1;
                                }
                            }

                            else {
                                votes[4] += 1;
                            }
                        }

                        // tree #6
                        if (x[0] <= 17.5) {
                            if (x[2] <= 10.5) {
                                votes[1] += 1;
                            }

                            else {
                                votes[0] += 1;
                            }
                        }

                        else {
                            if (x[1] <= 18.0) {
                                if (x[2] <= 7.5) {
                                    if (x[0] <= 52.0) {
                                        if (x[1] <= 13.0) {
                                            votes[2] += 1;
                                        }

                                        else {
                                            if (x[1] <= 15.5) {
                                                votes[3] += 1;
                                            }

                                            else {
                                                if (x[2] <= 3.5) {
                                                    votes[5] += 1;
                                                }

                                                else {
                                                    votes[2] += 1;
                                                }
                                            }
                                        }
                                    }

                                    else {
                                        votes[3] += 1;
                                    }
                                }

                                else {
                                    votes[4] += 1;
                                }
                            }

                            else {
                                votes[5] += 1;
                            }
                        }

                        // tree #7
                        if (x[0] <= 7.0) {
                            votes[0] += 1;
                        }

                        else {
                            if (x[1] <= 18.0) {
                                if (x[2] <= 7.5) {
                                    if (x[3] <= 232.0) {
                                        votes[2] += 1;
                                    }

                                    else {
                                        votes[3] += 1;
                                    }
                                }

                                else {
                                    votes[4] += 1;
                                }
                            }

                            else {
                                if (x[1] <= 30.5) {
                                    votes[5] += 1;
                                }

                                else {
                                    if (x[2] <= 3.5) {
                                        if (x[0] <= 17.0) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            votes[5] += 1;
                                        }
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }
                        }

                        // tree #8
                        if (x[0] <= 17.5) {
                            if (x[2] <= 10.5) {
                                votes[1] += 1;
                            }

                            else {
                                votes[0] += 1;
                            }
                        }

                        else {
                            if (x[1] <= 17.5) {
                                if (x[0] <= 49.5) {
                                    if (x[1] <= 11.0) {
                                        votes[4] += 1;
                                    }

                                    else {
                                        if (x[2] <= 2.5) {
                                            votes[5] += 1;
                                        }

                                        else {
                                            votes[2] += 1;
                                        }
                                    }
                                }

                                else {
                                    if (x[0] <= 51.5) {
                                        if (x[1] <= 12.0) {
                                            votes[2] += 1;
                                        }

                                        else {
                                            votes[3] += 1;
                                        }
                                    }

                                    else {
                                        votes[3] += 1;
                                    }
                                }
                            }

                            else {
                                votes[5] += 1;
                            }
                        }

                        // tree #9
                        if (x[2] <= 8.5) {
                            if (x[1] <= 17.5) {
                                if (x[2] <= 2.5) {
                                    if (x[1] <= 13.5) {
                                        votes[3] += 1;
                                    }

                                    else {
                                        votes[5] += 1;
                                    }
                                }

                                else {
                                    if (x[1] <= 13.0) {
                                        votes[2] += 1;
                                    }

                                    else {
                                        if (x[0] <= 43.5) {
                                            votes[2] += 1;
                                        }

                                        else {
                                            votes[3] += 1;
                                        }
                                    }
                                }
                            }

                            else {
                                if (x[2] <= 3.5) {
                                    if (x[0] <= 17.0) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[5] += 1;
                                    }
                                }

                                else {
                                    if (x[0] <= 20.0) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[5] += 1;
                                    }
                                }
                            }
                        }

                        else {
                            if (x[1] <= 13.5) {
                                votes[4] += 1;
                            }

                            else {
                                votes[0] += 1;
                            }
                        }

                        // tree #10
                        if (x[2] <= 8.5) {
                            if (x[0] <= 17.5) {
                                votes[1] += 1;
                            }

                            else {
                                if (x[0] <= 35.5) {
                                    votes[5] += 1;
                                }

                                else {
                                    if (x[0] <= 44.0) {
                                        votes[2] += 1;
                                    }

                                    else {
                                        if (x[3] <= 223.0) {
                                            votes[2] += 1;
                                        }

                                        else {
                                            votes[3] += 1;
                                        }
                                    }
                                }
                            }
                        }

                        else {
                            if (x[0] <= 14.5) {
                                votes[0] += 1;
                            }

                            else {
                                votes[4] += 1;
                            }
                        }

                        // tree #11
                        if (x[0] <= 7.0) {
                            votes[0] += 1;
                        }

                        else {
                            if (x[0] <= 17.5) {
                                if (x[3] <= 141.5) {
                                    votes[0] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }

                            else {
                                if (x[2] <= 7.5) {
                                    if (x[3] <= 186.5) {
                                        if (x[1] <= 17.5) {
                                            votes[2] += 1;
                                        }

                                        else {
                                            votes[5] += 1;
                                        }
                                    }

                                    else {
                                        if (x[0] <= 41.0) {
                                            votes[5] += 1;
                                        }

                                        else {
                                            votes[3] += 1;
                                        }
                                    }
                                }

                                else {
                                    votes[4] += 1;
                                }
                            }
                        }

                        // tree #12
                        if (x[0] <= 17.5) {
                            if (x[1] <= 29.0) {
                                votes[0] += 1;
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        else {
                            if (x[1] <= 18.0) {
                                if (x[0] <= 32.0) {
                                    votes[4] += 1;
                                }

                                else {
                                    if (x[3] <= 275.0) {
                                        if (x[2] <= 7.5) {
                                            votes[2] += 1;
                                        }

                                        else {
                                            votes[4] += 1;
                                        }
                                    }

                                    else {
                                        votes[3] += 1;
                                    }
                                }
                            }

                            else {
                                votes[5] += 1;
                            }
                        }

                        // tree #13
                        if (x[0] <= 17.5) {
                            if (x[1] <= 28.5) {
                                votes[0] += 1;
                            }

                            else {
                                if (x[1] <= 39.5) {
                                    votes[1] += 1;
                                }

                                else {
                                    if (x[2] <= 29.0) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }
                            }
                        }

                        else {
                            if (x[1] <= 17.5) {
                                if (x[3] <= 172.0) {
                                    if (x[3] <= 131.0) {
                                        if (x[1] <= 13.5) {
                                            votes[4] += 1;
                                        }

                                        else {
                                            votes[5] += 1;
                                        }
                                    }

                                    else {
                                        votes[2] += 1;
                                    }
                                }

                                else {
                                    if (x[1] <= 6.5) {
                                        votes[4] += 1;
                                    }

                                    else {
                                        if (x[0] <= 37.5) {
                                            votes[4] += 1;
                                        }

                                        else {
                                            votes[3] += 1;
                                        }
                                    }
                                }
                            }

                            else {
                                votes[5] += 1;
                            }
                        }

                        // tree #14
                        if (x[1] <= 17.5) {
                            if (x[2] <= 7.5) {
                                if (x[0] <= 44.0) {
                                    votes[2] += 1;
                                }

                                else {
                                    if (x[3] <= 234.5) {
                                        votes[2] += 1;
                                    }

                                    else {
                                        votes[3] += 1;
                                    }
                                }
                            }

                            else {
                                if (x[0] <= 17.5) {
                                    votes[0] += 1;
                                }

                                else {
                                    votes[4] += 1;
                                }
                            }
                        }

                        else {
                            if (x[0] <= 7.0) {
                                votes[0] += 1;
                            }

                            else {
                                if (x[1] <= 37.0) {
                                    if (x[1] <= 29.0) {
                                        votes[5] += 1;
                                    }

                                    else {
                                        if (x[3] <= 905.5) {
                                            if (x[3] <= 230.5) {
                                                votes[5] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }

                                        else {
                                            votes[5] += 1;
                                        }
                                    }
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }
                        }

                        // tree #15
                        if (x[1] <= 17.5) {
                            if (x[3] <= 172.0) {
                                if (x[1] <= 8.5) {
                                    votes[4] += 1;
                                }

                                else {
                                    if (x[3] <= 131.0) {
                                        if (x[2] <= 16.0) {
                                            if (x[0] <= 23.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[5] += 1;
                                            }
                                        }

                                        else {
                                            votes[4] += 1;
                                        }
                                    }

                                    else {
                                        votes[2] += 1;
                                    }
                                }
                            }

                            else {
                                if (x[2] <= 6.5) {
                                    votes[3] += 1;
                                }

                                else {
                                    votes[4] += 1;
                                }
                            }
                        }

                        else {
                            if (x[2] <= 14.0) {
                                if (x[1] <= 37.0) {
                                    if (x[0] <= 17.5) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[5] += 1;
                                    }
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }

                            else {
                                votes[0] += 1;
                            }
                        }

                        // tree #16
                        if (x[0] <= 17.5) {
                            if (x[2] <= 10.5) {
                                votes[1] += 1;
                            }

                            else {
                                votes[0] += 1;
                            }
                        }

                        else {
                            if (x[0] <= 48.0) {
                                if (x[2] <= 7.5) {
                                    if (x[0] <= 35.0) {
                                        votes[5] += 1;
                                    }

                                    else {
                                        votes[2] += 1;
                                    }
                                }

                                else {
                                    votes[4] += 1;
                                }
                            }

                            else {
                                if (x[3] <= 223.5) {
                                    votes[2] += 1;
                                }

                                else {
                                    votes[3] += 1;
                                }
                            }
                        }

                        // tree #17
                        if (x[1] <= 17.5) {
                            if (x[0] <= 49.0) {
                                if (x[2] <= 7.5) {
                                    if (x[3] <= 131.0) {
                                        votes[5] += 1;
                                    }

                                    else {
                                        votes[2] += 1;
                                    }
                                }

                                else {
                                    if (x[3] <= 51.0) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        votes[4] += 1;
                                    }
                                }
                            }

                            else {
                                if (x[0] <= 51.5) {
                                    if (x[1] <= 12.0) {
                                        votes[2] += 1;
                                    }

                                    else {
                                        votes[3] += 1;
                                    }
                                }

                                else {
                                    votes[3] += 1;
                                }
                            }
                        }

                        else {
                            if (x[1] <= 30.5) {
                                if (x[0] <= 10.5) {
                                    votes[0] += 1;
                                }

                                else {
                                    if (x[0] <= 18.0) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[5] += 1;
                                    }
                                }
                            }

                            else {
                                if (x[0] <= 17.0) {
                                    if (x[2] <= 29.5) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }

                                else {
                                    votes[5] += 1;
                                }
                            }
                        }

                        // tree #18
                        if (x[0] <= 17.5) {
                            if (x[0] <= 7.0) {
                                votes[0] += 1;
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        else {
                            if (x[2] <= 7.5) {
                                if (x[0] <= 35.0) {
                                    votes[5] += 1;
                                }

                                else {
                                    if (x[3] <= 235.0) {
                                        votes[2] += 1;
                                    }

                                    else {
                                        votes[3] += 1;
                                    }
                                }
                            }

                            else {
                                votes[4] += 1;
                            }
                        }

                        // tree #19
                        if (x[2] <= 8.5) {
                            if (x[0] <= 18.0) {
                                votes[1] += 1;
                            }

                            else {
                                if (x[0] <= 35.5) {
                                    votes[5] += 1;
                                }

                                else {
                                    if (x[3] <= 223.5) {
                                        votes[2] += 1;
                                    }

                                    else {
                                        votes[3] += 1;
                                    }
                                }
                            }
                        }

                        else {
                            if (x[1] <= 13.5) {
                                votes[4] += 1;
                            }

                            else {
                                votes[0] += 1;
                            }
                        }

                        // tree #20
                        if (x[2] <= 8.5) {
                            if (x[1] <= 17.5) {
                                if (x[0] <= 51.5) {
                                    if (x[0] <= 44.0) {
                                        if (x[0] <= 35.5) {
                                            votes[5] += 1;
                                        }

                                        else {
                                            votes[2] += 1;
                                        }
                                    }

                                    else {
                                        if (x[1] <= 12.0) {
                                            votes[2] += 1;
                                        }

                                        else {
                                            votes[3] += 1;
                                        }
                                    }
                                }

                                else {
                                    votes[3] += 1;
                                }
                            }

                            else {
                                if (x[0] <= 17.5) {
                                    votes[1] += 1;
                                }

                                else {
                                    votes[5] += 1;
                                }
                            }
                        }

                        else {
                            if (x[0] <= 18.0) {
                                votes[0] += 1;
                            }

                            else {
                                votes[4] += 1;
                            }
                        }

                        // return argmax of votes
                        uint8_t classIdx = 0;
                        float maxVotes = votes[0];

                        for (uint8_t i = 1; i < 6; i++) {
                            if (votes[i] > maxVotes) {
                                classIdx = i;
                                maxVotes = votes[i];
                            }
                        }

                        return classIdx;
                    }

                    /**
                    * Predict readable class name
                    */
                    const char* predictLabel(float *x) {
                        return idxToLabel(predict(x));
                    }

                    /**
                    * Convert class idx to readable name
                    */
                    const char* idxToLabel(uint8_t classIdx) {
                        switch (classIdx) {
                            case 0:
                            return "Blue";
                            case 1:
                            return "Green";
                            case 2:
                            return "NoData";
                            case 3:
                            return "Orange";
                            case 4:
                            return "Pink";
                            case 5:
                            return "Yellow";
                            default:
                            return "Houston we have a problem";
                        }
                    }

                protected:
                };
            }
        }
    }