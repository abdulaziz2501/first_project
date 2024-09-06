from django.db import models
from django.utils import timezone

class Elevator(models.Model):
    name = models.CharField(max_length=100)
    status = models.BooleanField(default=True)  # True - Working, False - Not Working
    last_checked = models.DateTimeField(default=timezone.now)

    def __str__(self):
        return self.name

    def update_status(self, status):
        self.status = status
        self.last_checked = timezone.now()
        self.save()
