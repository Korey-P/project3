# Horse Race - Procedural 

## **Pseudocode**
```plaintext
CONSTANT TRACK_LENGTH = 15
CONSTANT NUM_HORSES = 5

FUNCTION advance(horses)
    FOR i FROM 0 TO NUM_HORSES - 1
        SET coin TO RANDOM(0 or 1)
        IF coin == 1 THEN
            INCREMENT horses[i]
END FUNCTION

FUNCTION printRace(horses)
    FOR i FROM 0 TO NUM_HORSES - 1
        FOR j FROM 0 TO TRACK_LENGTH - 1
            IF j == horses[i] THEN
                PRINT i
            ELSE
                PRINT "."
        PRINT NEW LINE
END FUNCTION

FUNCTION checkWinner(horses)
    FOR i FROM 0 TO NUM_HORSES - 1
        IF horses[i] >= TRACK_LENGTH - 1 THEN
            PRINT "Horse " + i + " WINS!"
            RETURN true
    RETURN false
END FUNCTION

FUNCTION main()
    INITIALIZE horses array to all 0s
    SET raceOver TO false
    CALL RANDOM_SEED()

    PRINT "Press Enter to start the race..."
    WAIT FOR USER INPUT

    WHILE raceOver == false
        CLEAR SCREEN
        CALL advance(horses)
        CALL printRace(horses)
        SET raceOver TO CALL checkWinner(horses)
        IF raceOver == false THEN
            PRINT "Press Enter for the next turn..."
            WAIT FOR USER INPUT
END FUNCTION
END CLASS

FUNCTION main()
    CREATE Race object race
    CALL race.start()
END FUNCTION
