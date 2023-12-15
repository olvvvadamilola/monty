,>,                         # Accept two single-digit ASCII inputs
[                           # Start of loop to multiply
    >                       # Move to second number
    [                       # Start loop for multiplication
        -                   # Decrement first number
        <                   # Move to first number
        +                   # Increment result number
        >                   # Move to second number
    ]                       # End of loop for multiplication
    <                       # Move back to result number
    .                       # Print the result
]
