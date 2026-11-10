# Q4 – Decision Making

## Test Results

| Marks | Expected Grade |
|---:|:---:|
| 100 | S |
| 90 | S |
| 89 | A |
| 83 | A |
| 50 | D |
| 49 | F |
| 0 | F |
| -1 | Invalid (?) |
| 101 | Invalid (?) |

Both the else-if ladder and switch implementation produce the correct grades.

## Missing Break Experiment

If a break or return is removed from a switch case, execution falls through into subsequent cases. This can produce an incorrect grade.

## Why Switch Cannot Directly Test Ranges

A switch compares one expression against constant case values. It cannot directly test a range such as 75–84.

## Design Decision

An else-if ladder is suitable for ranges. A switch is suitable after converting marks into marks / 10.

For scholarship classification, a nested if structure can first check the grade and then check the family income band.

## Alternative Concept: Lookup Table

A lookup table can use:

char grades[11] = {'F','F','F','F','F','D','C','B','A','S','S'};

The grade can be accessed using grades[marks / 10], after validating marks.

Lookup table: O(1) time and O(11) space.
Switch: O(1) time and O(1) extra space.
Else-if ladder: Up to O(k) comparisons for k conditions.

## Conclusion

Both implementations correctly classify the tested marks. Input validation prevents invalid marks from receiving a normal grade.