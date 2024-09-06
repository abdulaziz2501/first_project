from django.contrib import admin
from .models import Elevator

@admin.register(Elevator)
class ElevatorAdmin(admin.ModelAdmin):
    list_display = ('name', 'status', 'last_checked')
    list_filter = ('status',)
