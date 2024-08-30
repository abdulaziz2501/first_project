from telegram import Update
from telegram.ext import Updater, CommandHandler, CallbackContext

# /start buyrug'ini bajarish
def start(update: Update, context: CallbackContext) -> None:
    update.message.reply_text('Salom! Men sizning yangi Telegram botingizman. /help buyrug\'ini yuboring.')

# /help buyrug'ini bajarish
def help_command(update: Update, context: CallbackContext) -> None:
    update.message.reply_text('Bu bot orqali siz quyidagi buyruqlardan foydalanishingiz mumkin:\n/start - Botni ishga tushirish\n/help - Yordam')

# Asosiy funksiya: botni ishga tushirish
def main() -> None:
    # API tokenini kiriting
    updater = Updater("7158427390:AAGmiMKa3Fx2TW01-ANC_KHTPSZ9VTc3KDA", use_context=True)

    # Dispatcher orqali handlerlarni qo'shish
    dispatcher = updater.dispatcher

    dispatcher.add_handler(CommandHandler("start", start))
    dispatcher.add_handler(CommandHandler("help", help_command))

    # Botni ishga tushirish
    updater.start_polling()

    # To'xtatishga qadar ishlatish
    updater.idle()

if __name__ == '__main__':
    main()
