namespace ES.Models;
public class UserCardDigits : ValueObject
{
    private readonly string _value;

    public static Result<UserCardDigits> Create(string cardDigits)
    {
        if (String.IsNullOrEmpty(cardDigits))
            return Result.Fail<UserCardDigits>("Card number cannot be an empty string.");

        cardDigits = cardDigits.Trim();
        if (!cardDigits.All(char.IsDigit))
            return Result.Fail<UserCardDigits>("Card number must only contain numbers.");
        if (cardDigits.Length != 3)
            return Result.Fail<UserCardDigits>("Card number must contain 3 digits.");

        return Result.Ok<UserCardDigits>(new UserCardDigits(cardDigits));
    }

    protected UserCardDigits(string value)
    {
        _value = value;
    }

    protected override IEnumerable<object> GetEqualityComponents()
    {
        yield return _value;
    }
    public static implicit operator string(UserCardDigits cardDigits) => cardDigits._value;
    public static explicit operator UserCardDigits(string str) => new UserCardDigits(str);
}