namespace ES.Models;
public class UserCardDate : ValueObject
{
    private readonly string _value;

    public static Result<UserCardDate> Create(string cardDate)
    {
        if (String.IsNullOrEmpty(cardDate))
            return Result.Fail<UserCardDate>("Card Date cannot be an empty string.");

        cardDate = cardDate.Trim();
        DateTime dateValue;
        if (DateTime.TryParse(cardDate, out dateValue))
            return Result.Ok<UserCardDate>(new UserCardDate(dateValue.ToShortDateString()));
        else
            return Result.Fail<UserCardDate>("Card Date must only contain Dates.");
    }

    protected UserCardDate(string value)
    {
        _value = value;
    }

    protected override IEnumerable<object> GetEqualityComponents()
    {
        yield return _value;
    }
    public static implicit operator string(UserCardDate cardDate) => cardDate._value;
    public static explicit operator UserCardDate(string str) => new UserCardDate(str);
}