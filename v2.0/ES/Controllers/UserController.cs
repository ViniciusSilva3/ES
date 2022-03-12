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
        Result<UserCardDate> cardCardDate = UserCardDate.Create(user.cardDate);

        Result result = Result.Combine(cpf, password, cardCardDate, cardDigits, cardNumber);

        if (result.IsNotSuccess)
            return new BadRequestResult();
        
        User newUser = new User(cpf.Value, cardCardDate.Value, cardDigits.Value, cardNumber.Value, password.Value);

        var createUserOperation = _userService.CreateUser(newUser);
        if (createUserOperation.IsNotSuccess)
            return new BadRequestObjectResult(createUserOperation.Error);

        return new OkResult();
    }
}
