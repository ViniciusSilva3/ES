using Microsoft.AspNetCore.Mvc;
using ES.Models;
using ES.Services;


namespace ES.Controllers;

[ApiController]
[Route("api/user")]
public class UserController : ControllerBase
{
    private readonly IUserService _userService;
    public UserController(IUserService userService)
    {
        _userService = userService;
    }

    [HttpPost]
    public ActionResult CreateUser(CreateUserModel user)
    {
        Result<UserCpf> cpf = UserCpf.Create(user.cpf);
        Result<UserPassword> password = UserPassword.Create(user.password);
        Result<UserCardNumber> cardNumber = UserCardNumber.Create(user.cardNumber);
        Result<UserCardDigits> cardDigits = UserCardDigits.Create(user.cardDigits);
        Result<UserCardDate> cardDate = UserCardDate.Create(user.cardDate);

        Result result = Result.Combine(cpf, password, cardDate, cardDigits, cardNumber);

        if (result.IsNotSuccess)
            return new BadRequestObjectResult(result.Error);
        
        User newUser = new User(cpf.Value, cardDate.Value, cardDigits.Value, cardNumber.Value, password.Value);

        var createUserOperation = _userService.CreateUser(newUser);
        if (createUserOperation.IsNotSuccess)
            return new BadRequestObjectResult(createUserOperation.Error);

        return new OkResult();
    }
}
